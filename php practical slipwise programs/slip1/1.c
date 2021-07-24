<html>
 <head> 
<style> 
span {  color: red;  font-size: 15px;  float: right; }
 </style> 
<script type="text/javascript" >  
function val_stud_name(inputfield,helptext)
   {
   if(inputfield.value.length == 0)  
 {  
  if(helptext != null)    
{    
 helptext.innerHTML= "* Student name should not be empty";  
  } 
   return false;   
 }   
else 
  { 
   if (helptext != null)     helptext.innerHTML = "";    
return true;
   } 
  }   
 function val_stud_age(inputfield,helptext)  
 { 
  if(1 >= inputfield.value || inputfield.value >= 20) 
 
{
    if(helptext != null)   
 { 
 
NR CLASSES, PUNE( 8796064387/ 90) Page 2  
    helptext.innerHTML= "* Age must be between 1 to 20"; 
   } 
   return false;  
  } 
  else if(1 <= inputfield.value || inputfield.value <= 20)   
{
    if (helptext != null)     helptext.innerHTML = "";   
 return true;   
} 
  }   
</script> 
</head>
 <body> 
<table align="center"> 
<tr> <td>
<label>Name</label>
</td> 
<td>
<input type="text" placeholder="Enter your name here" name="s_name" id="s_name" onblur="val_stud_name(this,document.getElementById('s_nm'));">
</td>
 </tr> 
<tr><td>
</td>
<td>
<span id="s_nm">
</span>
</td>
</tr>    
<tr>
 <td>
<label>Age</label>
</td> 
<td>
<input type="text" placeholder="Enter your age here" name="age" id="age" onblur="val_stud_age(this,document.getElementById('s_age'));">
</td> 
</tr>
 <tr>
<td>
</td>
<td>
<span id="s_age"></span>
</td></tr>    
<tr> <td><label>Mobile no </label>
</td> 
<td>
<input type="text" placeholder="Enter your mob here" name="s_mob" id="s_mob" onblur="val_nonEmpty(this,document.getElementById('s_mob'));">
</td>
 </tr>
 <tr>
<td>
</td>
<td>
<span id="s_mob">
</span>
</td>
</tr> 
<tr>
<th colspan="2">
<input type="submit" value="Submit">
<input type="RESET" value="Reset">
</th>
</tr>
 </table> 
</body> 
</html>   