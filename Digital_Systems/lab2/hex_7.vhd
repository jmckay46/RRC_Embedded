library ieee;
use ieee.std_logic_1164.all;

entity hex7_seg is
    port(
            d3, d2, d1, d0                  : in     std_logic;
            y6, y5, y4, y3, y2, y1, y0      : out    std_logic;

end hex7_seg;

architecture seven_segment of hex7_seg is

    signal selected_data    :   std_logic_vector(3 downto 0);
    signal display          :   std_logic_vector(6 downto 0);

begin
    --common anode configuration
    --concencate the inputs into a signal
    selected_data <= d3 & d2 & d1 & d0;

    with selected_data select
         display <=  "0000001" when "0000",  --display 0
                     "1001111" when "0001",  --display 1
                     "0100100" when "0010",  --display 2
                     "0110000" when "0011",  --display 3
                     "0011001" when "0100",  --display 4
                     "0010010" when "0101",  --display 5
                     "0000010" when "0110",  --display 6
                     "0001101" when "0111",  --display 7
                     "0000000" when "1000",  --display 8
                     "0001000" when "1001",  --display 9
                     "1111111" when others;