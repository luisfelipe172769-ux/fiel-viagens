/**
 * Lógica da FielViagens
 * Projeto de Extensão UNINOVE 2026
 */

function buscar() {
    const input = document.getElementById('inputDestino');
    const destino = input.value.trim();

    if (destino) {
        exibirModal(destino);
    } else {
        animarErro(input);
    }
}

/**
 * Cria um modal dinâmico para evitar o uso de alert()
 */
function exibirModal(destino) {
    const modal = document.createElement('div');
    modal.className = "fixed inset-0 bg-black/60 backdrop-blur-sm flex items-center justify-center p-4 z-[100] animate-in fade-in duration-300";
    
    modal.innerHTML = `
        <div class="bg-white p-8 rounded-3xl max-w-sm w-full shadow-2xl text-center transform scale-95 animate-in zoom-in duration-300">
            <div class="w-16 h-16 bg-green-100 text-green-600 rounded-full flex items-center justify-center mx-auto mb-4">
                <i class="fa-solid fa-check text-2xl"></i>
            </div>
            <h3 class="text-2xl font-bold mb-2">Destino Encontrado</h3>
            <p class="text-gray-600 mb-6">
                Temos pacotes exclusivos para <strong>${destino}</strong> com monitoramento residencial ativo incluso.
            </p>
            <button id="closeModal" class="w-full bg-black text-white py-4 rounded-xl font-bold hover:bg-gray-800 transition-colors">
                Ver Detalhes
            </button>
        </div>
    `;

    document.body.appendChild(modal);

    document.getElementById('closeModal').onclick = () => {
        modal.classList.add('animate-out', 'fade-out', 'zoom-out');
        setTimeout(() => modal.remove(), 200);
    };
}

/**
 * Feedback visual para campos vazios
 */
function animarErro(elemento) {
    elemento.classList.add('border-red-500', 'bg-red-50');
    elemento.placeholder = "Por favor, digite um destino";
    
    setTimeout(() => {
        elemento.classList.remove('border-red-500', 'bg-red-50');
        elemento.placeholder = "Para onde vamos?";
    }, 2500);
}

// Log de inicialização (bom para os prints da consola no trabalho)
console.log("FielViagens: Core System v1.0 [Protocolo Pet-Safe Ready]");