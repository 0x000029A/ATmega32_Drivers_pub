48 row, 84 column outputs
Serial interface maximum 4.0 Mbits/s
SDIN > Serial input
SCLK > clock input 4Mbits/s
D/C' > High: Data || Low: Command
SCE' > Low = Data clocked in || High = Data off
RST' > Reset, active low

Init:
1) Function set (H = 1) -> bias system -> set Vop -> Temp control 
2) Function set (H = 0) - > display control -> y address -> x address


Address Counter (AC)
The address counter assigns addresses to the display
data RAM for writing. The X-address X6 to X0 and the
Y-address Y2 to Y0 are set separately. After a write
operation, the address counter is automatically
incremented by 1, according to the V flag.

Display Data RAM (DDRAM)
The DDRAM is a 48 * 84 bit static RAM which stores the
display data. The RAM is divided into six banks of 84 bytes
(6 * 8 * 84 bits). During RAM access, data is transferred
to the RAM through the serial interface. There is a direct
correspondence between the X-address and the column
output number.