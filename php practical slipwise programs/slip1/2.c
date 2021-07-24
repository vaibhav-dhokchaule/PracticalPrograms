XML file : university.xml 
<?xml version="1.0" encoding="UTF-8"?>
 <?xml-stylesheet type="text/css" href="university.css"?>
 <Univ> 
 <U_info> 
  <Uname>Pune University</Uname> 
  <City>Pune</City> 
  <Rank>First</Rank> 
 </U_info>  
<U_info>  
 <Uname>Mumbai University</Uname>  
 <City>Mumbai</City> 
  <Rank>Third</Rank>
  </U_info>
  <U_info>
   <Uname>Latur University</Uname> 
  <City>Latur</City>  
 <Rank>Fifth</Rank> 
 </U_info> 
</Univ> 
------------------------------------------------  
CSS file : university.css 

Uname
{ 
 color:black;
  font-family: copperplate Gothic Light; 
 font-size: 16pt; 
 font: bold;
 } 
City,Rank
 {
  color:yellow;
  font-family:arial; 
 font-size: 12pt;
  font: bold; 
}  
--------------------------------------------------
PHP file :
 <?php 
 $xml=simplexml_load_file("university.xml") or die("eror:cannot create object");
  echo "<table border=1 align=center>";
  echo "<tr><td>Univercity Name</td><td>City</td><td>Rank</td></tr>";  
foreach($xml->children() as $uni)
  {
   echo "<tr><td>".$uni->Uname."</td>";
   echo "<td>".$uni->City."</td>"; 
  echo "<td>".$uni->Rank."</td></tr>"; 
 } 
 echo "<table>"; 
?>  
