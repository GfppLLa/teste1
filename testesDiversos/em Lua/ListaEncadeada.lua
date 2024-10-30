--tentativa nova lista encadeada
--em lua usa-se valores ao inves de ponteirtos
--entao é uma especie de tabela também mas nao como no c 


ListaEncadeada = {} --lista table é criada localmente
ListaEncadeada.__index = ListaEncadeada --aqui ainda nao sei direito

--construtor de uma nova lista, por assim dizer
function ListaEncadeada:nova ()
    local self = setmetatable({}, ListaEncadeada) --cria a metatabela da tabela, 
                                                  --cria uma tabela vazia a faz associalção
                                                  --self é variavel, a  estancia atual da tabela
    self.head = nil --cria a variavel, head do  primeiro nó vazio inicialmente
    return self
end
--inserir um valor no inicio da lista
function ListaEncadeada:inserirNoInicio(valor)
    local novoNo = {valor=valor, proximo=self.head} --cria e instancia uma tabela local de vetores
    self.head=novoNo --self head criada em outra funcao recebe a tabela novoNo
end

function ListaEncadeada:inserirNoFim(valor)
    local novoNo = {valor = valor, proximo=nil} --cria uma instancia lcoal de tabela chamada novoNo
    if self.head ==nil then --se a head tiver vazia essa vai sr a primeira
        self.head = novoNo --head vazio recebe o head criado
    else                    --se nao for nil ja existe um elemento, entao se poe dps dele
        local atual = self.head --atual recebe o head da lsiata atual
        while atual.proximo do --enquanto houver algo no campo proximo do vetor atual while roda
                atual=atual.proximo --vetor 'atual' recebe todos os campos de proximo
        end
        atual.proximo=novoNo 
    end
    
end

function ListaEncadeada:removerDoInicio()
    if self.head ==nil then
        print("a lista esta vazia")
    else
            self.head = self.head.proximo    
    end
end

function ListaEncadeada:mostrar()
    local atual =self.head
    while atual do
        print(atual.valor)
        atual=atual.proximo
    end
end
