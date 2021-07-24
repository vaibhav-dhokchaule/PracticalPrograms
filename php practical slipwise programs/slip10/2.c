HTML file :
 <html> 
<body> 
<form action="slip10_Q2.php" method=get>
 <center>
<h2>For Cone & Cylinder</h2>
 <table>
 <tr><td>Enter Radius </td><td><input type="text" name="r"></td></tr>
 <tr><td>Enter Height</td><td> <input type="text" name="h"></td></tr>
 <tr><td><input type="radio" name=op value=1>Cone</td> <td><input type="radio" name=op value=2>Cylinder</td></tr>
 </table> 
<table>
 <center>
<h2>For Sphere</h2>
</center>
 <tr><td>Enter Radius</td><td> <input type="text" name="r1"></td></tr>
 <tr><td></td><td><input type="radio" name=op value=3>Sphere</td></tr>
 <tr><td></td><td><input type="submit" value="SUBMIT"></td></tr>
 </table> 
</center>
 </form> 
</body>
 </html>
---------------------------------------------------------------------------  
PHP file :
 <?php
  define('pi',3.14);  interface shape 
 {    
function calc_area($r,$h);    
 function calc_vol($r,$h);   
 }     
class sphere implements shape 
 {   
function calc_area($r,$r) 
  {   
 return 4*pi*$r*$r;   
 }  
  function calc_vol($r,$r)   
{   
 return (4/3)*pi*$r*$r*$r; 
  } 
 }  
 class cylinder implements shape 
 {  
 function calc_area($r,$h) 
  {  
  return 2*pi*$r*($r+$h);   
 }  
  function calc_vol($r,$h)  
 {  
  return pi*$r*$r*$h;   
} 
 }  
 class cone implements shape 
 {  
 function calc_area($r,$h) 
  { 
   return 0.5*$r*$r*$h;   
 }  
  function calc_vol($r,$h)   
{    
return $r*$r*$r*$h;   
}  
}  
 $op=$_GET['op'];  
 switch($op)  
{   
 case 1 : 
$r=$_GET['r'];       
$h=$_GET['h'];       
$ob=new cone();      
 $a=$ob->calc_area($r,$h);       
$v=$ob->calc_vol($r,$h);      
echo "Area of cone is".$a."<br>Volume of Cone is".$v;     
 break;  
  case 2 :
 $r=$_GET['r'];      
 $h=$_GET['h'];      
 $ob=new cylinder();       
$a=$ob->calc_area($r,$h);       
$v=$ob->calc_vol($r,$h);     
 echo "Area of Cylinder is".$a."<br>Volume of Cylinder is".$v;     
 break;         
case 3 : 
$r=$_GET['r'];      
 $ob=new sphere();      
 $a=$ob->calc_area($r,$r);       
$v=$ob->calc_vol($r,$r);      
echo "Area of Sphere is".$a."<br>Volume of Sphere is".$v;      
 break;   
 } 
?>  
