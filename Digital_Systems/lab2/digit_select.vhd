library ieee;
use ieee.std_logic_1164.all;

entity digit_select is
    port(
            a_in        : in    std_logic_vector (3 downto 0);
            b_in        : in    std_logic_vector (3 downto 0);
            sel         : in    std_logic_vector;
            display     : out   std_logic_vector (0 to 6));

end digit_select;

architecture mux of digit_select is

component quad2to1mux
    port(
            a       : in    std_logic_vector (3 downto 0);
            b       : in    std_logic_vector (3 downto 0);
            s       : in    std_logic_vector;
            y       : out   std_logic_vector (3 downto 0));
end component;

component hex7seg
    port(
            d       : in    std_logic_vector (3 downto 0);
            y       : out   std_logic_vector (0 to 6));
end component;

--declare a signal to connect the two components

signal selected_data    :   std_logic_vector (3 downto 0);
begin
--concatenate the output from quad2to1mux into selected_data
    selected_data <= Y3 & Y2 & Y1 & Y0;

--separate each port into inputs of hex7seg
    d(3) <= selected_data(3);
    d(2) <= selected_data(2);
    d(1) <= selected_data(1);
    d(0) <= selected_data(0);

end mux;
