library ieee;
use ieee.std_logic_1164.all;

entity hex7seg is
	port(
			d		:in std_logic_vector(3 downto 0);

			y		:out std_logic_vector(7 downto 0));
end hex7seg;

architecture circuit of hex7seg is
begin
	when "0000" => y <= "00000001";
	when "0001" => y <= "00000010";
	when "0010" => y <= "00000011";
	when "0011" => y <= "00000100";
	when "0100" => y <= "00000101";
