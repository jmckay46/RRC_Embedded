--4_ALU.vhd
--4 bit Arthimetic Logic Unit

library ieee;
use library.ieee.std_logic_1164;

entity 4_ALU is
port(
		a			: in	std_logic_vector(3 downto 0);
		b			: in	std_logic_vector(3 downto 0);
		c_in		: in	std_logic;
		op_code		: in	std_logic_vector(3 downto 0);

		y			: out std_logic_vector(3 downto 0);
		c_out		: out std_logic_vector);
end 4_ALU;

architecture logic of 4_ALU is
begin
--signal declaration for signed/unsigned outputs
	signal y_logic			std_logic_vector(3 downto 0);
	signal y_unsigned 	std_logic_vector(3 downto 0);
	signal y_signed		std_logic_vector(3 downto 0);

--all statements must be concurrent (when or select)
with op_code select
		y_logic <=		not a 	 when "000",
						a and b	 when "001",
						a or b	 when "010",
						a xor b	 when "011",

