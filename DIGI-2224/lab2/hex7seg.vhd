--hex7seg.vhd
--common anode configuration

library ieee;
use ieee.std_logic_1164.all;

entity hex7seg is
	port(
			d		:	in	std_logic_vector(3 downto 0);
			y		:	out	std_logic_vector(0 to 6));

end hex7seg;

architecture decoder of hex7seg is
begin

	with d select
		y <=   	 "0000001" when "0000",  --display 0
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

end decoder;
