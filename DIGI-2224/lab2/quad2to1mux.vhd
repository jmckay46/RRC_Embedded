library ieee;
use ieee.std_logic_1164.all;

entity quad2to1mux is
port (
		a		:in	std_logic_vector(3 downto 0);
		b		:in	std_logic_vector(3 downto 0);
		s		:in	std_logic;

		y		:out	std_logic_vector(3 downto 0));
end quad2to1mux;

architecture mux of quad2to1mux is
begin
	with s select
		y <= a when '0', b when '1', "0000" when others;
end mux;
