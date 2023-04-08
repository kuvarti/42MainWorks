<?php
	define( 'DB_NAME', 'inceptiondb' );
	define( 'DB_USER', 'nolan' );
	define( 'DB_PASSWORD', '123' );
	define( 'DB_HOST', 'mariadb' );
	define( 'DB_CHARSET', 'utf8' );
	define( 'DB_COLLATE', '' );
	define( 'WP_ALLOW_REPAIR', true );

	define('AUTH_KEY',         'Hqzn.qnBc[C=z>X4J<fQ3z{S`x-HIEDS !U/J*pkW9 m+WR#?C:D6):TL]~ZS4+g');
	define('SECURE_AUTH_KEY',  '`wUKlPo,5IBp?Vh?UfRX1BEHwjnQR1~;=vD0vn+e`0<|!MW~xZO611tEp:Rp&(yf');
	define('LOGGED_IN_KEY',    '=(N{B)2%&^%]W9GU|R`!gT03WhPVivG<]FcuWta-%|cxDFZWY~(d#-:)fGtp!>W7');
	define('NONCE_KEY',        '%h_ Gwk=X|lx+Ik}`RpWyv)=]=zrOH[UQ?ty25.GOW{^Cooa>L-3/G163SV=_10-');
	define('AUTH_SALT',        'n`*K8i6++zJ-svwlHKihvH|2.,@x-E)SlM&:NB71Ta*~S<Vi+]Y`^cnd{d-Wp4`,');
	define('SECURE_AUTH_SALT', 'pG 06@=1IN17ce}WN$=VA8M9`DS`%FB8~E9y.s!e9TiOt~Te_|096Uf[>=&t^jJ5');
	define('LOGGED_IN_SALT',   '0XFl76,{Jl%~43_$RiYs-M^`U|#BYv}SS|?U;4w@Zi ;6&0+k~PWeDo[%<$c>eX)');
	define('NONCE_SALT',       ')b&N=Q e^Ttq]9}+EG|*#B+i>Qk;9/dEfgRYX-U!<)gT(u30;q75=FKy3s9{?VvY');

	define( 'WP_REDIS_HOST', 'redis' );
	define( 'WP_REDIS_PORT', 6379 );

	define( 'WP_CACHE', true );

	$table_prefix = 'wp_';

	define( 'WP_DEBUG', true );
	if ( ! defined( 'ABSPATH' ) ) {
		define( 'ABSPATH', __DIR__ . '/' );
	}
	require_once ABSPATH . 'wp-settings.php';
?>
