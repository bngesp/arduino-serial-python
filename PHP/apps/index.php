<?php

/**
* Author : Bassirou NGOM
* date : 04/01/2019
* licence: MIT
*/

include 'function.php';

if(isset($_GET['temperature'])){
	$temperature = $_GET['temperature'];
	echo "$temperature";
	if($temperature>0){
		$destinataires = ['bassiroungom@esp.sn' => 'My Name', 
				  'bassiroungom26@gmail.com' => 'Bassirou NGOM'];

		$objet = "Alert System";

		$message  = "Alert!! Alert !!. La température du systeme est : ".$temperature;
		

		sendMail($destinataires, $objet, $message);

	}
}