<?php
/**
* Author : Bassirou NGOM
* date : 04/01/2019
* licence: MIT
*/


require_once '../vendor/autoload.php';

function sendmail($to, $objet, $msg){
	//creation du transport
	$trans = new Swift_SmtpTransport('smtp.gmail.com', 587,'tls');
	$transport =  $trans
					->setUsername('projetsettp@gmail.com')
					->setPassword('projetandtp2017');

	$mailer = new Swift_Mailer($transport);
	// Create a message
	$message = (new Swift_Message($objet))
	  ->setFrom(['projetsettp@gmail.com' => 'Monitoring System'])
	  ->setTo($to)
	  ->setBody($msg);

	// Send the message
	$result = $mailer->send($message);
	return $result;

}
