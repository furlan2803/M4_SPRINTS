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
    }else{

        // Se nenhum jogador marcou 3 ícones em sequência, verifica se todas as células do tabuleiro estão preenchidas
        if(getClass(1) != "" && getClass(2) != "" && getClass(3) != "" && getClass(4) != "" && getClass(5) != "" && getClass(6) != "" && getClass(7) != "" && getClass(8) != "" && getClass(9) != ""  ){
            // Se todas as células do tabuleiro estiverem preenchidas, adiciona a classe "show" para mostrar o elemento com o ícone de empate
            runBot = false;
            bot(runBot);
            empate();
        }

    }
}

///////////////////////////////////////////////////////////////////////////


// Iniciando a conexão com o servidor
const MQTT_HOST = "broker.hivemq.com";
const MQTT_PORT = 8000;
const MQTT_CLIENT_ID = "5e8391cc-cecc-4d70-bd1d-731d17e7f7cg"

// Criando a instancia para o cliente 
let client = new Paho.MQTT.Client(MQTT_HOST, MQTT_PORT, MQTT_CLIENT_ID);

// Função que instancia o canal quando o cliente conecta ao servidor
function onConnect() {

    // Conectando o cliente ao servidor
    client.subscribe("INTELI/Semana7/JogoDaVelha");

}

// Função que recebe a mensagem do servidor e manda a resposta para o cliente, quando o "X" vence
function acenderX() {
    newmesg = new Paho.MQTT.Message("acenderX");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}

// Função que recebe a mensagem do servidor e manda a resposta para o cliente, quando da empate
function acenderEmpate() {
    newmesg = new Paho.MQTT.Message("acenderEmpate");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}

// Função que recebe a mensagem do servidor e manda a resposta para o cliente, quando a "O" vence
function acenderO(){
    newmesg = new Paho.MQTT.Message("acenderO");
    newmesg.destinationName = "INTELI/Semana7/JogoDaVelha";
    client.send(newmesg);
}


// Instanciamento a função que executa quando o cliente é desconectado do servidor
function onConnectionLost(responseObject) {

    // Verifica se o cliente foi desconectado do servidor
    if (responseObject.errorCode !== 0) {
      console.log(`A conexão foi encerrada: ${responseObject.errorMessage}`);
    }

}

// Função que executa quando o cliente recebe uma mensagem do servidor
function onMessageArrived(message) {

    // Verifica se as mensagens do servidor estão chegando corretamente
    if(message.destinationName == "INTELI/Semana7/JogoDaVelha" && message.payloadString == "Mandando mensagem!") {

        newmesg = new Paho.MQTT.Message("Recebi a sua mensagem aqui.");
        newmesg.destinationName = message.destinationName;
        client.send(newmesg);
    }
}


// Iniciando a conexão com o servidor
client.onConnectionLost = onConnectionLost;
client.onMessageArrived = onMessageArrived;

client.connect({ 
    onSuccess: onConnect
});



// Função que executa para verificar o jogador que venceu
function quemGanhou() {
    // Se o jogador que venceu for o "X", manda mensagem para o servidor e recarrega a página
    if (jogadorSign == "X") {
        acenderX();
        window.location.reload();
    }
    // Se o jogador que venceu for o "O", manda mensagem para o servidor e recarrega a página
    if(jogadorSign == "O") {
        acenderO();
        window.location.reload();
    }
}
// Se o jogo der "Empate", manda mensagem para o servidor e recarrega a página
function empate() {
    acenderEmpate();
    window.location.reload();
}