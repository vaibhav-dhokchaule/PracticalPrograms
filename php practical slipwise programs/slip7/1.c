HTML file : 
<html> 
<body>
 <form action="slip7_Q1.php" method="post" enctype=multipart/form-data>
 <input type=file name=file></br>
 <input type="radio" name="op" value="1">Display type of file<br>
 <input type="radio" name="op" value="2">Delete a file<br> 
<input type=submit value="Upload">
 </form>
 </body> 
</html> 
--------------------------- 
PHP file :
 <?
$op=$_POST['op'];
  switch($op)
  {  
 case 1 :
 echo "File name : ".$_FILES['file']['name']."</br>";  
  $t=$_FILES['file']['type'];  
  echo "Type  :".$t."</br>";  
  break;      
   case 2 : 
 $f_name=$_FILES['file']['name'];  
  $fh = fopen('$f_name','a');   
 fclose($fh);   
 unlink($f_name);  
  echo "Deleted file is : ".$_FILES['file']['name']."</br>";  
  break;  
} 
?>  
