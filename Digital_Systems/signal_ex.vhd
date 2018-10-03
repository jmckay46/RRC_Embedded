library ieee;
use ieee.std_logic_1164.all;

entity signal_ex is
  port(
          a, b, c     :in    std_logic;
          w, x, y, z  :out   std_logic);
          
end signal_ex;

architecture sig of signal_ex is
  signal inputs : std_logic_vector(2 downto 0);
  signal outputs: std_logic_vector(3 downto 0);
  
begin
--Conatenate input ports into 3-bit signal
  inputs <= a & b & c;
  
with inputs select
      outputs       <=    "1000" when "000",
                          "0100" when "001",
                          "0110" when "010",
                          "1001" when "011",
                          "0110" when "100",
                          "0001" when "101",
                          "1001" when "110",
                          "0010" when "111",
                          "0000" when others;
      
--separate signal into individual ports
w <= outputs(3);
x <= outputs(2);
y <= outputs(1);
z <= outputs(0);

end sig;
