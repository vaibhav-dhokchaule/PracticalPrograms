HTML file :
 <html>
 <body> 
<form action="slip12_Q2.php" method="get">
 <center> 
<h3><input type="text" name="str" maxlength="20">
<input type="radio" name="op" value="1">Insert element into array</h3> 
<h3><input type="radio" name="op" value="2">Delete last element from array</h3>
 <h3><input type="radio" name="op" value="3">Display all elements from array</h3>
 <input type="submit" value="Submit">
 </center> 
</form>
 </body> 
</html>  
-------------------------------------------------------------
PHP file : 
<?php 
 $str = $_GET['str'];  
 $op = $_GET['op']; 
 $stack = array("orange", "banana", "apple", "raspberry"); 
 switch($op) 
 {  
 case 1 :
 echo "string is :: $str<br>";   
   array_push($stack,"$str");     
 var_dump($stack);     
 break;  
 case 2 :
 $last_elt = array_pop($stack);   
 var_dump($stack);    
var_dump('deleted element is :'.$last_elt);    
 break;   
case 3 : var_dump($stack);    
break; 
 }
 ?>  