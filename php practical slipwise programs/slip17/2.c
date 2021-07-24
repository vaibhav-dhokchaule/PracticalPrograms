HTML file : 
<html> 
<script type="text/javascript">
 function display() 
{ 
 ob = new XMLHttpRequest(); 
 ob.open("GET","slip17_2.php");  
ob.send(); 
 ob.onreadystatechange = function() 
 {  
 if(ob.readyState == 4 && ob.status == 200)  
 document.getElementById("i").innerHTML = ob.responseText; 
 }  
} 
</script>  
<body> 
<h2>DISPLAY INFORMATION OF TEACHER</h2> 
<input type=submit value="DISPLAY INFORMATION" onclick=display()>
 <span id=i>
</span> 
</body>
 </html> 
------------------------------------------------------------------- 
PHP file :
 <?php 
$con_string = "host=localhost dbname=bcs_slips port=5432  user=postgres password=nrc"; 
$con = pg_connect($con_string);  
echo "</br>"; 
$q = "select * from teacher;"; 
$rs = pg_query($con,$q) or die("Cannot Execute query"); 
while($row = pg_fetch_row($rs))
 echo "$row[0] $row[1] $row[2]\n</br>";  
pg_close(); 
?>    