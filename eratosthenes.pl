use strict;

my $max =  10000000;
my @prime = ();

for(0...$max){
	$prime[$_] = 1;
}

for (2...sqrt($max)){
	if( $prime[$_] != 0 ){
		my $n = $_;
		for(my $i = 2;$i*$n <= $max;$i++){
			$prime[$n*$i]=0;
		}
	}
}

for(2...$max){
	if($prime[$_] != 0){
		print "$_\n";
	}
}
