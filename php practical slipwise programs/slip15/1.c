HTML file : 
<html> <script type="text/javascript"> 
 function display() 
 { 
  var ob=false;   
ob=new XMLHttpRequest();
   var fnm=document.getElementById("fnm").value;  
  var lnm=document.getElementById("lnm").value;  
   ob.open("GET","slip1.php?fnm="+fnm+"&lnm="+lnm);   
 ob.send();    
  ob.onreadystatechange=function() 
  {  
if(ob.readyState==4 && ob.status==200)   
 {     
 if(ob.responseText==2)     
document.getElementById("i").innerHTML="Fill The Text Boxes";  
    else   
   {     
  alert(ob.responseText);        
  document.getElementById("i").innerHTML=ob.responseText;    
  }   
 }   
}  
 } 
</script>  
<body>
 Enter First name<input type=text name=fnm id=fnm><br>
 Enter last name<input type=text name=lnm id=lnm><br>
 <input type=submit value=SUBMIT onclick=display()><br> 
<span id=i></span>
 </body>
 </html>
-------------------------------------------------    
PHP file : 
<?php 
$fnm = $_GET['fnm'];
 $lnm = $_GET['lnm'];
 if((!empty($fnm))  && (!empty($lnm))) 
 { 
 echo "First Name is $fnm<br>"; 
  echo "Last Name is $lnm";  
 } 
  else echo "2"; 
?>   
 
---------------------------------------- 
