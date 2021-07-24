HTML file : 
<html> 
<head> 
<script type="text/javascript" >  
function m1(str)
  {  
 var ob=false;   
ob=new XMLHttpRequest();  
 ob.open("GET","slip20_2.php?q="+str);   
ob.send();     
 ob.onreadystatechange=function()   
{    
if(ob.readyState==4 && ob.status==200)            
 document.getElementById("a").innerHTML=ob.responseText;  
 }   
}
 </script>
 </head>  
<body>
 <form>
 Enter Name Of Student :<input type=text name=search size="20" onkeyup="m1(form.search.value)">
 <input type=button value="submit" >
<!--onclick="m1(form.search.value)"-->
 <!-- onclick="matches(form.search.value)">-->
 </form> suggestions :<span id="a">
</span><br> 
</body> 
</html> 
------------------------------------------------------------- 
PHP file :  
<?php 
 $a=array("RAMESH","SURESH","RAJ","SEEMA","PUJA","SIYA","AJAY","SAMEER","VIJAY","VIN AY","VIRAJ"); 
 $q=$_GET['q'];  
  if(strlen($q)>0) 
 { 
   $match="";  
 for($i=0;$i<count($a);$i++)   
{   
 if(strtolower($q)==strtolower(substr($a[$i],0,strlen($q))))    
 {     
 if($match=="")     
 {      
 $match=$a[$i];         
}        
else     
 {       
$match=$match.",".$a[$i];      
}     
}    
}     
if($match=="")   
{    
echo "No Suggestios";   
}   
else   
{    
echo $match;   
}  
} 
?>   