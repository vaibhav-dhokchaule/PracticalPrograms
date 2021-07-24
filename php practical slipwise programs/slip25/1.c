PHP file :
 <?php $arr = array(array ( 1, 2, 3, 4, 5) , array ( 6, 7, 3 ) ,); 
echo "before<br>";
 var_dump($arr);  
foreach($arr as $k1=>$q) 
 {   
  foreach($q as $k2=>$r)
     {        
if($r == 3)       
 {           
unset($arr[$k1][$k2]);        
}     
} 
} 
echo "<br><br>after:<br>"; 
print_r($arr); 
?>  