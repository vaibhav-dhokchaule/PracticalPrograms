PHP file :
 <?php
 $sourceFname="test.txt";
 $fp1=fopen("test.txt","r");
 $fp2=fopen
fwrite($fp2,fread($fp1,filesize($sourceFname))); 
echo "Data Copied"; 
?>  