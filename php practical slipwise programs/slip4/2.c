HTML file : 
<html> 
<body> 
<form action="slip4_Q2.php" method=get>
 <center>
 <table>
 <tr><td>Enter No1</td><td><input type="text" name="a"></td></tr>
 <tr><td>Enter No2</td><td><input type="text" name="b"></td></tr>
 <tr><td></td><td><input type="submit" value="SUBMIT"></td></tr>
 </table>
 </center>
 </form> 
</body> 
</html> 
----------------------------------------------------
PHP file : 
<?php
  class Calculate        
{          
 public $a;           
public $b;                 
 function __construct($a,$b)           
{              
$this->a=$a;              
$this->b=$b;            
}            
public function add()           
 {             
 $c=$this->a+$this->b;              
echo"Addition = $c<br>";           
 }
 public function subtract()            
{ 
 $c=$this->a-$this->b;              
echo"Subtract = $c<br>";            
}              
public function multiply()            
{              
$c=$this->a*$this->b;              
 echo"Multiplication = $c<br>";            
}            
public function div()            
{           
 $c=$this->a/$this->b;              
echo"Division = $c";           
 }      
}
 $x=$_GET['a']; 
$y=$_GET['b']; 
$calc=new Calculate($x,$y);
 $calc->add();
 $calc->subtract();
 $calc->multiply();
 $calc->div();
 ?>  