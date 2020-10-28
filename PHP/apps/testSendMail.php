<?php 
/**
* Author : Bassirou NGOM
* date : 04/01/2019
* licence: MIT
*/
include 'function.php';

$destinataires = ['bassiroungom@esp.sn' => 'My Name', 
				  'bassiroungom26@gmail.com' => 'Bassirou NGOM'];

$objet = "Alert System";

$message  = "Test envoi alerte par Mail";

sendMail($destinataires, $objet, $message);
