nrows = 8;
ncols = 8;

leds = new Array(nrows).fill(0).map(function(row){
	return new Array(ncols).fill(0);});

function toggleLed (row, col) {
	leds[row][col] = leds[row][col] === 1 ? 0 : 1;
	var elem = document.getElementById ('led' + row + '_' + col);
	if (leds[row][col] === 0) {
		elem.classList.remove("on");
	} else {
		elem.classList.add("on");
	}
	printCode();
}

function printCode () {
	var code = "";
	for (i=0; i < nrows; i++) {
		var number=0;
		for (j=0; j < ncols; j++) {
			number = number << 1 | leds[i][j];
		}
		code = code + "0x" + number.toString(16) + ", ";
	}
	var elem = document.getElementById ('result');
	elem.innerText = "byte character[8]={" + code.slice(0, -2) + "};";
}
