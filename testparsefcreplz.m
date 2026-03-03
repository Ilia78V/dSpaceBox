[PCD1_1, PCD1_2, freq_rel_percent, ...
          status_word, ...
          fu_ctrl_ready, fu_ready, fault_trip, fault_no_trip, bus_control_active, ...
          bcc_ok] = parse_fc_reply(ones(1, 8))

function [PCD1_1, PCD1_2, freq_rel_percent, ...
          status_word, ...
          fu_ctrl_ready, fu_ready, fault_trip, fault_no_trip, bus_control_active, ...
          bcc_ok] = parse_fc_reply(u)
%#codegen
% Parse 8-byte FC reply built by your current build_fc_rx_telegram()
% Layout: [STX, LEN, ADDR, STW_HI, STW_LO, OUT_HI, OUT_LO, BCC]
% Bit mapping (matches your TX builder with msbpos()):
%   fu_ctrl_ready      -> bit15
%   fu_ready           -> bit14
%   fault_trip         -> bit13
%   fault_no_trip      -> bit12
%   bus_control_active -> bit6

    % ---- basic checks ----
    if numel(u) < 8
        error('parse_fc_reply:BadLength','u must have at least 8 bytes');
    end
    u = uint8(u(:).'); % row uint8

    % ---- BCC (XOR of bytes 1..7) ----
    b = uint8(0);
    for k = 1:7
        b = bitxor(b, u(k));
    end
    bcc_ok = (b == u(8));

    % ---- status word bytes ----
    PCD1_1 = u(4); % high byte (bits 15..8)
    PCD1_2 = u(5); % low  byte (bits 7..0)

    % Full 16-bit status word: [HI<<8 | LO]
    status_word = bitor( bitshift(uint16(PCD1_1),8), uint16(PCD1_2) );

    % Helper to read a single LSB-indexed bit (0..15)
    getbit = @(w, n) bitand(w, bitshift(uint16(1), n)) ~= 0;

    % ---- flags (LSB indexing) matching your TX mapping ----
    fu_ctrl_ready      = getbit(status_word, 15); % msbpos(0)
    fu_ready           = getbit(status_word, 14); % msbpos(1)
    fault_trip         = getbit(status_word, 13); % msbpos(2)
    fault_no_trip      = getbit(status_word, 12); % msbpos(3)
    bus_control_active = getbit(status_word,  6); % msbpos(9)

    % ---- OUT (Q14) -> relative frequency (%) ----
    q14 = bitor( bitshift(uint16(u(6)),8), uint16(u(7)) );
    freq_rel_percent = double(q14) * (100.0/16384.0);
end
