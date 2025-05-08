const Human = document.getElementById("MyCheckbox");
const Male = document.getElementById("Gender1");
const Female = document.getElementById("Gender2");
const Submit = document.getElementById("MySubmit");

Submit.onclick = function(){
    
    const username = document.getElementById("MyUsername").value;
    if(Human.checked){
        if(Male.checked){
            document.getElementById("p1").textContent = `Hello Mr ${username}`;
        }
        if(Female.checked){
            document.getElementById("p1").textContent = `Hello Miss ${username}`;
        }
    }
    else{
        document.getElementById("p1").textContent = `You Must be HUMAN!`; 
    }
}

