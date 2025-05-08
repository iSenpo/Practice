console.log(`Hello`);
let x=0;
document.getElementById("reset").onclick = function(){
    x=0;
    document.getElementById("countlabel").textContent = `${x}`;
}
document.getElementById("decrease").onclick = function(){
    x--;
    document.getElementById("countlabel").textContent = `${x}`;
}
document.getElementById("increase").onclick = function(){
    x++;
    document.getElementById("countlabel").textContent = `${x}`;
}

