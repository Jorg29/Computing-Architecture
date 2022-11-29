library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
use ieee.NUMERIC_STD.all;

entity ERGASIA3 is
generic(
constant N: natural:=1 --
);
Port(A,B :in STD_LOGIC_VECTOR(7 downto 0); --2 inputs 8-bit
name_sel :in  STD_LOGIC_VECTOR(3 downto 0); --1 input 4-bit
ALU_Out:out  STD_LOGIC_VECTOR(7 downto 0); --1 output 8-bit 
Carryout : out std_logic); -- Carryout το flag
end ERGASIA3;
architecture ERGASIA of ERGASIA3 IS

signal name_out: std_logic_vector (7 downto 0);
signal tmp: std_logic_vector (8 downto 0);

begin
process(A,B,name_sel)
begin
case(name_sel)is
when "0000"=> --ΠΡΟΣΘΕΣΗ
name_out<= A+B;
when "0001"=> --ΑΦΑΙΡΕΣΗ
name_out<= A-B;
when "0010"=> --ΠΟΛΛΑΠΛΑΣΙΑΣΜΟΣ
name_out<= std_logic_vector(to_unsigned((to_integer(unsigned(A)) * to_integer(unsigned(B))),8)) ;
when "0011"=> --ΔΙΑΙΡΕΣΗ
name_out<= std_logic_vector(to_unsigned(to_integer(unsigned(A)) / to_integer(unsigned(B)),8)) ;
when "0100"=> --ΑΡΙΣΤΕΡΗ ΟΛΙΣΘΗΣΗ
name_out<= std_logic_vector(unsigned(A) sll N);
when "0101"=> --ΔΕΞΙΑ ΟΛΙΣΘΗΣΗ
name_out<= std_logic_vector(unsigned(A) srl N);
when "0110"=> --ΠΕΡΙΣΤΡΟΦΗ ΑΡΙΣΤΕΡΑ
name_out<= std_logic_vector(unsigned(A) rol N);
when "0111"=> --ΠΕΡΙΣΤΡΟΦΗ ΔΕΞΙΑ
name_out<= std_logic_vector(unsigned(A) ror N);
when "1000"=> --ΛΟΓΙΚΟ AND
name_out<= A and B;
when "1001"=> --ΛΟΓΙΚΟ OR
name_out<= A or B;
when "1010"=> --ΛΟΓΙΚΟ XOR
name_out<= A xor B;
when "1011"=> --ΛΟΓΙΚΟ NOR
name_out<= A nor B;
when "1100"=> --ΛΟΓΙΚΟ NAND
name_out<= A nand B;
when "1101"=> --ΛΟΓΙΚΟ XNOR
name_out<= A xnor B; 
when"1110"=> --A>0

if(A>B)then
name_out<=x"01";
else
name_out<=x"00";
end if;
when"1111"=>
if(A=B)then
name_out<=x"01";
else
name_out<=x"00";
end if;
when others=>name_out<=A+B;
end case;
end process;
ALU_Out<=name_out;
tmp<=('0' & A)+('0' & B);
Carryout<=tmp(8);
end ERGASIA;