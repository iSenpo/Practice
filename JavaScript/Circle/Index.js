console.log(`Hello`);
let username;
const PI = 3;
let S,P,radius;
document.getElementById("mySubmit").onclick = function(){

    username = document.getElementById("myText").value ;
    document.getElementById("myH1").textContent = `Hello ${username}`;
}
document.getElementById("Submit2").onclick = function(){
    radius = document.getElementById("radius").value;
    S = PI * radius * radius ;
    P = PI * 2 * radius ;
    document.getElementById("H1-2").textContent = `S = ${S} And P = ${P}`;
}

