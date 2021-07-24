HTML file : 
<html> 
<head>
 <style>
 span 
{  
font-size: 25px; 
}
 table
 { 
 color: blueviolet; ;
 } 
</style>  
<script type="text/javascript" > 
 function print()  
{  
 var ob=false;   
ob=new XMLHttpRequest();     
ob.open("GET","slip14_Q2.php?");
 ob.send();     
 ob.onreadystatechange=function()  
 {   
 if(ob.readyState==4 && ob.status==200)   
 {    
 document.getElementById("i").innerHTML=ob.responseText;     
}  
 }  
}  
</script> 
 </head>  
<body>
 <center>
 <h3>Display the contents of a contact.dat file </h3>
 <br><input  type="button"  value=Print onclick="print()" >
 <span id="i">
</span>
 </center> 
</body>
 </html>  
-------------------------------------------------------------------------------------
Dat file : contact.dat 

1  Isha  65768798  98765432  Daughter
 2  Sweety  65235689  87654329  Mother  
------------------------------------------------------------------
PHP file :
 <?php 
 $fp = fopen('contact.dat','r'); 
 echo "<table border=1>"; 
 echo "<tr><th>Sr. No.</th><th>Name</th><th>Residence No.</th><th>Mob. no.</th><th>Relation</th></tr>";  
 while($row =  fscanf($fp,"%s %s %s %s %s")) 
 {
   echo "<tr>";  
 foreach($row as $r)   
{   
 echo "<td>$r</td>";    
 }     
echo "</tr>";  
}   
echo "</table>";  
fclose($fp); 
?>  
