HTML file :
 <?php 
   echo "Your IP Address Is : " . $_SERVER['REMOTE_ADDR'] . "<br>";   
 echo "Browser Detection / Information : " . $_SERVER['HTTP_USER_AGENT'] . "<br>";  
  echo "You Came From A Page Called : " .$_SERVER['HTTP_REFERER']. "<br>"; 
?> 