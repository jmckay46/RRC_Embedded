--add4par.vhd
--4 bit parallel adder, using 4 instances of the component full_add
library ieee;
use ieee.std_logic_1164.all;

entity add4par is
	port (
				c0			: in 	std_logic;
				a, b		: in	std_logic_vector(4 downto 1);
				c4			: out std_logic;
				sum		: out std_logic_vector(4 downto 1));
end add4par;

architecture adder of add4par is 
	--component declaration -> full_add function is defined in full_add.vhd 
	component full_add	
		port(
				a, b, c_in	: in 	std_logic;
				c_out, sum	: out std_logic);
	end component;
	--define a signal for internal carry bits
	signal c : std_logic_vector(3 downto 1);
begin
	--Four component instantiation statements
	adder1: full_add
		port map (
						a		=> a(1),
						b		=> b(1),
						c_in 	=> c0,
						c_out => c(1),
						sum 	=> sum(1));
						
	adder2: full_add
		port map (
						a		=> a(2),
						b		=> b(2),
						c_in	=> c(1),
						c_out => c(2),
						sum 	=> sum(2));
						
	adder3: full_add
		port map (
						a		=> a(3),
						b		=> b(3),
						c_in	=> c(2),
						c_out => c(3),
						sum	=> sum(3));
						
	adder4: full_add
		port map (
						a		=> a(4),
						b		=> b(4),
						c_in	=> c(3),
						c_out => c(4),
						sum	=> sum(4));
						
end adder;
