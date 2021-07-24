HTML file : 
<html> 
<body> 
<form action=slip13_2.php> 
Enter Hospital Name :<input type=text name=a id=a><br>  
<input type=submit value="DISPLAY" >
 </form>
 </body> 
</html>  
----------------------------------------------------
PHP file :
 <?php
 $con_string="host = localhost dbname=bcs_slips port=5432  user=postgres password=nrc";  
$con = pg_connect($con_string);  
$a = $_GET['a'];
 echo $a; 
echo "</br>";
 $q = "select dname from doctor,hospital where hname='$a' and hospital.hosp_no = doctor.hosp_no;";  
$rs = pg_query($con,$q) ;  
if($rs) 
{ 
echo "in";
 while($row=pg_fetch_row($rs)) echo "$row[0]\n</br>"; 
}
 pg_close(); 
?> 