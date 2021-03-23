<?php
	/*************************************************************
	*															 *
	*		CÉLIO YUTAKA 	 *
	*															 *
	**************************************************************
	* Analisador Léxico para uma linguagem de expressões		 *
	*************************************************************/

	$arrayOP = array('*','/','+','-');
	$arrayNumeros = array('0','1','2','3','4','5','6','7','8','9');
	$arrayPontuacao = array('(',')');
	$arrayTipo = array(1=>'num', 2=>'operador', 3=>'pontuacao');
	$simbolos = array(
			'operador' => $arrayOP,
			'numero' => $arrayNumeros,
			'pontuacao' => $arrayPontuacao,
			'tipo' => $arrayTipo);


	$arrayEquacoes[1] = '1+2+3+3*6';//24
	$arrayEquacoes[2] = '10+1';//11
	$arrayEquacoes[3] = '20-10';//10
	$arrayEquacoes[4] = '20-(10*2)';//0
	$arrayEquacoes[5] = '45+(675+31)-20000';//-19249
	$arrayEquacoes[6] = '36+2*(25+(18-(5-2)*3))';//104
	$arrayEquacoes[7] = '8+3*7-5+15/3';//29
	$arrayEquacoes[8] = '10*[8/8]+(8-8)';//IMP
	$arrayEquacoes[10] = '10*8/{8+(8-8)}';//IMP
	//$equacao = '10+(10+5)-1';
	foreach ($arrayEquacoes as $cod => $equacao) {
		echo '<h1>['.$cod.'] Equação = '.$equacao.'</h1><br>';
		echo '<h2>Análise Léxica</h2><br>';
		analiseLexica($equacao,$simbolos);
		echo '<br>';
		echo '<h2>Solução da equação</h2><br>';
		while(strrpos($equacao, '(') or strrpos($equacao, ')'))
		{
			$posPA = strrpos($equacao, '(');
			$novaStr = substr($equacao, $posPA);
			$posPF = strpos($novaStr,')');

			$str_com_parenteses = substr($novaStr, 0, $posPF+1);
			$str_dentro_parenteses = substr($novaStr, 1, $posPF-1);


			$resultado = calcularSemParenteses($str_dentro_parenteses,$arrayOP);

			$equacao = str_replace($str_com_parenteses, $resultado, $equacao);

		}
		$resultado = calcularSemParenteses($equacao,$arrayOP);
		echo 'Resultado = '.$resultado.'<hr>';
		
	}

	function analiseLexica($strEq, $arraysimbolos)
	{
		$tamanho = strlen($strEq);
		$arrayToken = array();
		for ($i=0; $i < $tamanho; $i++) { 
			$achou = false;
			$tipo = 0;
			$c = $strEq[$i];
			foreach ($arraysimbolos['numero'] as $numero) 
			{
				if ($c == $numero)
				{
					$arrayToken[$i] = array('num' => $c);
					$achou = true;
					$tipo = 1;
				}
			}
			foreach ($arraysimbolos['operador'] as $numero) 
			{
				if ($c == $numero)
				{
					$arrayToken[$i] = array('operador' => $c);
					$achou = true;
					$tipo = 2;
				}
			}
			foreach ($arraysimbolos['pontuacao'] as $numero) 
			{
				if ($c == $numero)
				{
					$arrayToken[$i] = array('pontuacao' => $c);
					$achou = true;
					$tipo = 3;
				}
			}
			if (!$achou)
			{
				$str = 'Erro: caractere inválido: "'.$c.'"<br>';
			}
			else
			{
				$str =  "<&nbsp;".$arraysimbolos["tipo"][$tipo].','.$c.'><br>';
			}
			echo $str;
		}
	}


	function calcularSemParenteses($strEq,$arrayOP)
	{
		$strEq_ant = '';
		while($strEq_ant != $strEq){
			echo $strEq.'<br>';
			$strEq_ant = $strEq;
			foreach ($arrayOP as $op) {
				$pos = strpos($strEq, $op);
				if($pos)//achou operador
				{

					$n1 = numeroAntes($strEq,$pos,$arrayOP);
					$n2 = numeroDepois($strEq,$pos,$arrayOP);
					$resultado = calcular($n1,$op,$n2);
					if (!strcmp($resultado,'impossivel'))
						return 'Impossível';
					$strEquacao_3 = $n1.$op.$n2;
					
					$strEq = str_replace($strEquacao_3, $resultado, $strEq);
					
				}
			}
		}
		if (is_numeric($strEq))
			return $strEq;
	}

	function calcular($n1,$op,$n2)
	{
		switch ($op) {

			case '*':
				return $n1*$n2;
				break;
			case '/':
				if ($n2 == 0){
					echo 'Erro: Divisão por 0 (zero)<br>';
					return 'impossivel';
				}
				else{
					return $n1/$n2;
				}
				break;
			case '+':
				return $n1+$n2;
				break;
			case '-':
				return $n1-$n2;
				break;
		}
	}

	function numeroAntes($strEq,$pos,$arrayOP)
	{
		$tamanho = strlen($strEq);
		//var_dump($tamanho);
		$p  = 0;
		$naoOP = false;
		$n1 = '';
		for ($i = $pos-1 ; $i >= 0 AND $naoOP == false; $i--)
		{
			foreach ($arrayOP as $op) {
				if ($strEq[$i] == $op){
					$naoOP = true;

				}
			}
			if (!$naoOP)
			{
				$n1 .= $strEq[$i];
			}

		}
		$n1 = strrev($n1);
		return $n1;
	}

	function numeroDepois($strEq,$pos,$arrayOP)
	{
		$tamanho = strlen($strEq);
		//var_dump($tamanho);
		$p  = 0;
		$naoOP = false;
		$n2 = '';
		for ($i = $pos+1 ; $i < $tamanho AND $naoOP == false; $i++)
		{

			foreach ($arrayOP as $op) {
				if ($strEq[$i] == $op){
					$naoOP = true;
				}
			}
			if (!$naoOP)
			{
				$n2 .= $strEq[$i];
			}

		}
		return $n2;
	}



?>	
