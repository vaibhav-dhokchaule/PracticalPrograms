HTML file : 
<html>
 <body>  
<form action="slip22_2.php" method="get">
 <center>  
<table> 
<tr><td>Enter 1st String : </td><td><input type="text" name="str1"></td></tr>
 <tr><td>Enter 2nd String : </td><td><input type="text" name="str2"></td></tr> 
<tr><td>Enter String To Replace : </td><td><input type="text" name="str3"></td></tr>
 <tr><td>Occurance</td><td><input type="radio" name="ch" value=1></td></tr>
 <tr><td>Replace</td><td><input type="radio" name="ch" value=2></td></tr>
 <tr><td></td><td><input type="submit" value=Next></td></tr>
 </table> 
</center>  
</form>
 </body> 
</html> 
--------------------------------------------------- 
PHP file :
 <?php
 $str1 = $_GET['str1'];
 $str2 = $_GET['str2']; 
$str3 = $_GET['str3'];
 $ch = $_GET['ch'];  
echo "First String is = $str1.<br><br>";
 echo "second String is = ".$str2."<br><br>";
 echo "String for Replace is = ".$str3."<br><br>";  
If(strlen($str1)>strlen($str2))
 {   
switch($ch)   
{   
case 1 :
 $pos = strpos($str1,$str2);    
if($pos != 0)    
echo "string '$str2' Not present at the start of '$str1'.<br>";    
else echo "string '$str2' present at the start of '$str1'.<br>";   
 break; 
  case 2 : 
$str4 = str_replace($str2,$str3,$str1);   
 echo "After replacing string $str4";   
 break;    
} 
 } 
else 
{   
switch($ch)   
{   
case 1 :
 $pos = strpos($str2,$str1);    
if($pos != 0)   
 echo "string '$str1' Not present at the start of '$str2'.<br>";     
else  echo "string '$str1' present at the start of '$str2'.<br>";   
 break;   case 2 : $str4 = str_replace($str1,$str3,$str2);  
  echo "After replacing string $str4";   
 break; 
  } 
}
 ?>  