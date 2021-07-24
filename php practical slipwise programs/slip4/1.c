HTML file : 
<html>
 <head>
 <style>
 span {  color : red;  font-size : 25px; }
 </style>  
<script type = "text/javascript" > 
 function check_vowels(str) 
 {  
 var ob = false; 
  ob = new XMLHttpRequest(); 
  ob.open("GET","slip4_Q1.php?string="+str);
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
 <h3>Enter Sting: <input type="text" name="str" id="str" maxlength="20"></h3>
 <input type="submit" value="Check Vowels" onclick="check_vowels(str.value)">
<br><br><span id="i"></span> 
</center> 
</body>
 </html>  
-----------------------------------------------------------------
PHP file :
 <?php 
 $a=$_GET['string']; 
 $l=strlen($a); 
 $v_cnt=0;
  for($i=0;$i<$l;$i++)
  { 
  if(( $a[$i] == 'a') || ($a[$i] == 'e') || ($a[$i] == 'i') || ($a[$i] == 'o') || ($a[$i] == 'u') || ($a[$i] == 'A') || ($a[$i] == 'E') || ($a[$i] == 'I') || ($a[$i] == 'O') || ($a[$i] == 'U'))   
  $v_cnt++;
  }  
 echo "Total vowels are : $v_cnt";
 ?>  
