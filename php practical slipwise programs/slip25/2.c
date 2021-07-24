HTML file :
 <html> 
<script type="text/javascript"> 
function display() 
{     
ob = new XMLHttpRequest();    
 var a = document.getElementById("a").value;  
ob.open("GET","slip25_2.php?a="+a); 
 ob.send();  
ob.onreadystatechange = function()  
{ 
 if(ob.readyState == 4 && ob.status == 200)   
document.getElementById("i").innerHTML = ob.responseText; 
 }  
} 
</script>   
<body>  
Enter Actor Name :<input type=text name=a id=a><br> 
<input type=submit value="DISPLAY MOVIE NAME" onclick=display()><br>
 <span id=i>
</span> 
</body>
 </html>  
----------------------------------------------------
PHP file :
 <?php 
$con_string = "host=localhost dbname=bcs_slips port=5432  user=postgres password=nrc";  
$con = pg_connect($con_string);  
$a = $_GET['a']; 
echo $a; 
echo "</br>";
 $q = "select movie.mno,mname,r_yr from movie,actor where aname='$a' and movie.mno = actor.mno;";
 $rs = pg_query($con,$q) or die("Cannot Execute query");  
while($row = pg_fetch_row($rs)) 
echo "$row[0] $row[1] $row[2]\n</br>";  
pg_close(); 
?>           