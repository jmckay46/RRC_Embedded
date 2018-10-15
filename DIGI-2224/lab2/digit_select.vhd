library ieee;
use ieee.std_logic_1164.all;

entity digit_select is
port(
		a_in 		: in std_logic_vector (3 downto 0);
		b_in 		: in std_logic_vector (3 downto 0);
		sel 		: in std_logic;
		
		display 	: out std_logic_vector (0 to 6));		
end digit_select;

architecture mux of digit_select is

--Component declaration is the same as the entity declaration in quad2to1mux
component quad2to1mux
port(
		a 		: in std_logic_vector (3 downto 0);
		b 		: in std_logic_vector (3 downto 0);
		s 		: in std_logic;
		
		y 		: out std_logic_vector (3 downto 0));
end component;

-- Component declaration is the same as the entity declaration n hex7seg
component hex7seg
port(
		d 		: in std_logic_vector(3 downto 0);
		
		y 		: out std_logic_vector(0 to 6));
end component;

--declare a signal to connect the two components
signal selected_data : std_logic_vector(3 downto 0);
begin
--explicit component instantiation 
multiplexer: quad2to1mux
port map(	s	=>		sel,
		a	=>		a_in,
		b	=>		b_in,
		y	=>		selected_data);
				
decoder: hex7seg
port map(	d	=>		selected_data,
		y	=>		display);
				
end mux;
