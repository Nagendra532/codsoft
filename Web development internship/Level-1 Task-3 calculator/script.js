let currentInput = '';

function addToScreen(value) {
    if (value === 'DEL') {
        currentInput = currentInput.slice(0, -1);
    } else {
        currentInput += value;
    }
    document.getElementById('displayScreen').value = currentInput;
}


function calculate() {
    try {
        let result = eval(currentInput);
        document.getElementById('displayScreen').value = result;
        currentInput = result.toString();
    } catch (error) {
        document.getElementById('displayScreen').value = 'Error';
    }
}

function clearScreen() {
    currentInput = '';
    document.getElementById('displayScreen').value = '';
}
