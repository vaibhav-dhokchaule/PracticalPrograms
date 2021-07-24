<html>
 <head>
 <style>
 span
 { 
 color: red; 
 font-size: 25px;  
} 
</style>  
<script type="text/javascript" > 
 function count() 
 {  
 var ob=false;
   ob=new XMLHttpRequest();    
 var eid=document.getElementById("eid").value; 
    ob.open("GET","slip10_Q1.php?emailid="+eid); 
  ob.send();   
   ob.onreadystatechange=function()  
 {   
 if(ob.readyState==4 && ob.status==200) 
   document.getElementById("i").innerHTML=ob.responseText; 
   } 
 }
  </script> 
</head>  
<body>
 <center>
 <br>Email ID :<input type=text  name=eid id=eid>
 <br><input  type="button"  value=Show onclick="count()" >
 <br><br><span id="i"></span>
 </center>
 </body>
</html> 
---------------------------------------------------------- 
PHP file :
 <?php 
 $eid=$_GET['emailid']; 
 $cnt_1 = substr_count($eid,"@");
  $cnt_2 = substr_count($eid,".");
  echo "total count of @ is $cnt_1 and total count of .(dot) is $cnt_2"; 
?>