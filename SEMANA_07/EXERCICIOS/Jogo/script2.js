// Definição de todas as classes que serão manipuladas para exercerem alguma função específica

const selectabuleiro = document.querySelector(".select-tabuleiro"),
selectXBtn = selectabuleiro.querySelector(".opcaoJogador .jogadorX"),
selectOBtn = selectabuleiro.querySelector(".opcaoJogador .jogadorO"),
playBoard = document.querySelector(".play-board"),
alltabuleiro = document.querySelectorAll("section span"),
jogadors = document.querySelector(".jogadors");


// Sessão responsável por fazer os ícones aparecerem no tabuleiro, confome o clique do usuário

window.onload = ()=> {
    // Passa por todos os elementos do tabuleiro e adiciona um evento de clique, quando uma célula for clicada, a função "clickedtabuleiro" é chamada
    for (let i = 0; i < alltabuleiro.length; i++) {
        alltabuleiro[i].setAttribute("onclick","clickedtabuleiro(this)");
        
    }

    // Seleciona o ícone do jogador X, e adiciona a classe "active" para que o jogador X seja o primeiro a jogar
    selectXBtn.onclick = ()=>{
        selectabuleiro.classList.add("hide");
        playBoard.classList.add("show");
    }

    // Seleciona o ícone do jogador O, e adiciona a classe "active" para que o jogador O seja o primeiro a jogar
    selectOBtn.onclick = ()=>{
        selectabuleiro.classList.add("hide");
        playBoard.classList.add("show");
        jogadors.setAttribute("class","jogadors active jogador");
    }
}

// Definição dos ícones que serão utilizados para representar os jogadores
let jogadorXIcon = "fas fa-times";
let jogadorOIcon = "far fa-circle";
let jogadorSign = "X";
let runBot = true;


// Função que é chamada quando uma célula do tabuleiro é clicada
function clickedtabuleiro(element){
    // Verifica se o jogador O está ativo, se sim, adiciona o ícone do jogador 0 na célula clicada
    if(jogadors.classList.contains("jogador")){
        jogadorSign = "O";
        element.innerHTML = `<i class="${jogadorOIcon}"></i>`;
        jogadors.classList.remove("active");
        element.setAttribute("id", jogadorSign);
    }
    // Verifica se o jogador X está ativo, se sim, adiciona o ícone do jogador X na célula clicada
    else{
        jogadorSign = "X";
        element.innerHTML = `<i class="${jogadorXIcon}"></i>`;
        jogadors.classList.add("active");
        element.setAttribute("id", jogadorSign);
    }
    // Desabilita o clique na célula já clicada
    selectWinner();
    element.style.pointerEvents = "none";
    let randomDelayTime = ((Math.random() * 1000) + 200).toFixed();
    setTimeout(()=>{
        bot(runBot);
    },randomDelayTime);
    
}

// Função que faz o bot jogar
function bot(runBot){

        // Verifica se o bot está ativo
        if(runBot){
        let array = [];
        jogadorSign = "O";

        // Passa por todas as células do tabuleiro e verifica se a célula está vazia, se sim, adiciona o índice da célula no array
        for (let i = 0; i < alltabuleiro.length; i++) {
            if(alltabuleiro[i].childElementCount == 0){
                array.push(i);
            }
            
        }

        // Gera um número aleatório para selecionar uma célula do array
        let randomtabuleiro = array[Math.floor(Math.random() * array.length)];

        // Verifica se o jogador X está ativo, se sim, adiciona o ícone do jogador X na célula selecionada
        if(array.length > 0){
            if(jogadors.classList.contains("jogador")){
                jogadorSign = "X";
                alltabuleiro[randomtabuleiro].innerHTML = `<i class="${jogadorXIcon}"></i>`;
                jogadors.classList.add("active");
                alltabuleiro[randomtabuleiro].setAttribute("id", jogadorSign);
            
            }
            // Verifica se o jogador O está ativo, se sim, adiciona o ícone do jogador O na célula selecionada
            else{
                alltabuleiro[randomtabuleiro].innerHTML = `<i class="${jogadorOIcon}"></i>`;
                jogadors.classList.remove("active");
                alltabuleiro[randomtabuleiro].setAttribute("id", jogadorSign);
            } 
            selectWinner(); 
        }
        // Desabilita o clique na célula já clicada
        alltabuleiro[randomtabuleiro].style.pointerEvents = "none";
    }
}

// Função que verifica se o jogador X ou O ganhou
function getClass(idname){
    return document.querySelector(".tabuleiro"+ idname).id;
}

// Função que verificação a combinação de ícones e define o vencedor
function checkClass(val1,val2,val3,sign){
    if(getClass(val1) == sign && getClass(val2) == sign && getClass(val3) == sign){
        return true;
    }
}


function selectWinner(){

    // Define as possíveis combinações aceitas para que um jogador seja o vencedor do jogo
    if(checkClass(1,2,3,jogadorSign) || checkClass(4,5,6,jogadorSign) || checkClass(7,8,9,jogadorSign) || checkClass(1,4,7,jogadorSign) || checkClass(2,5,8,jogadorSign) || checkClass(3,6,9,jogadorSign) || checkClass(1,5,9,jogadorSign) || checkClass(3,5,7,jogadorSign)){

        // Verifica se existe algum jogador vencedor, se sim, adiciona a classe "show" para mostrar o elemento com o ícone do jogador que venceu
        runBot = false;
        bot(runBot);
        quemGanhou();
        // setTimeout(()=>{
        //     playBoard.classList.remove("show");
        //     resulttabuleiro.classList.add("show");
        // },700);
        // wonText.innerHTML = `Jogador  <p>${jogadorSign}</p>  Ganhou!`;
    }else{

        // Se nenhum jogador marcou 3 ícones em sequência, verifica se todas as células do tabuleiro estão preenchidas
        if(getClass(1) != "" && getClass(2) != "" && getClass(3) != "" && getClass(4) != "" && getClass(5) != "" && getClass(6) != "" && getClass(7) != "" && getClass(8) != "" && getClass(9) != ""  ){
            // Se todas as células do tabuleiro estiverem preenchidas, adiciona a classe "show" para mostrar o elemento com o ícone de empate
            runBot = false;
            bot(runBot);
            empate();
            // setTimeout(()=>{
            //     playBoard.classList.remove("show");
            //     resulttabuleiro.classList.add("show");
            // },700);
            // wonText.textContent = `Jogo Empatou!`;
        }

    }
}

///////////////////////////////////////////////////////////////////////////


// Instancing mqtt server info.
const MQTT_HOST = "broker.hivemq.com";
const MQTT_PORT = 8000;
const MQTT_CLIENT_ID = "5e8391cc-cecc-4d70-bd1d-731d17e7f7cg"

// Creating a client instance.
let client = new Paho.MQTT.Client(MQTT_HOST, MQTT_PORT, MQTT_CLIENT_ID);

// Instancing a function to be called when the client connects.
function onConnect() {

    // Subscribe to a topic called "".
    client.subscribe("INTELI/Semana7/JogoDaVelha");

    // message = new Paho.MQTT.Message("Oi, deu tudo certo!");
    // message.destinationName = "Inteli/Elias/Jogo";
    // client.send(message);

}

function acenderX() {
    newmesg = new Paho.MQTT.Message("acenderX");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}

function acenderEmpate() {
    newmesg = new Paho.MQTT.Message("acenderEmpate");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}

function acenderO(){
    newmesg = new Paho.MQTT.Message("acenderO");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}


// Instancing a function to be called when the client disconnects.
function onConnectionLost(responseObject) {

    if (responseObject.errorCode !== 0) {
      console.log(`A conexão foi encerrada: ${responseObject.errorMessage}`);
    }

}

// Instancing a function to be called when a message arrives.
function onMessageArrived(message) {

    if(message.destinationName == "INTELI/Semana7/JogoDaVelha" && message.payloadString == "Mandando mensagem!") {

        newmesg = new Paho.MQTT.Message("Recebi a sua mensagem aqui.");
        newmesg.destinationName = message.destinationName;
        client.send(newmesg);

    }

    console.log(message.destinationName);

    console.log(`Uma mensagem acabou de chegar: ${message.payloadString}`);

}


// Setting up callback handlers. 
client.onConnectionLost = onConnectionLost;
client.onMessageArrived = onMessageArrived;

// Connecting to the server.
client.connect({ 
    onSuccess: onConnect
});



// TESTEEE DE QUEM GANHOU

function quemGanhou() {
    if (jogadorSign == "X") {
        acenderX();
        window.location.reload();
    }
    
    if(jogadorSign == "O") {
        acenderO();
        window.location.reload();
    }
}

function empate() {
    acenderEmpate();
    window.location.reload();
}