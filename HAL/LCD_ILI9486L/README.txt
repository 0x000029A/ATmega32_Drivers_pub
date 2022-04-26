- 8 bit parallel

steps:
- Be sure to execute a power-on reset after supplying power.

PINS:
- RESX : External reset input. Initializes the chip with a low input.
- CSX : A chip select signal. Low: the chip is selected and accessible. High: the chip is not selected and not accessible.
- RS \ D/CX : - Parallel interface (D/CX): The signal for command or parameter select. Low: Command. High: Parameter.
- WRX : Serves as a write signal and writes data at the rising edge. 
- RDX : Serves as a read signal and read data at  the rising edge. 
- D[0-7] : Data pins.

D/CX    RDX     WRX     Operation
L       H       RISE    Write command 
H       RISE    H       Read parameter 
H       H       RISE    Write parameter

Write Sequence:
WRX is driven from high to low then pulled back to high.
CS is low to select chip
RES is high
RS as what i choose
RDX is high