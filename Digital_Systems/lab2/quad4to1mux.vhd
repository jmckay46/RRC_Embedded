library ieee;
use ieee.std_logic_1164.all;

entity quad4to1mux is
port (
		a		:in	std_logic_vector(3 downto 0);
		b		:in	std_logic_vector(3 downto 0);
		s		:in	std_logic;

		y		:out	std_logic_vector(3 downto 0));
end quad4to1mux;

architecture circuit of quad4to1mux is
begin
		y <= a when (s = '1') else b;
end circuit;
