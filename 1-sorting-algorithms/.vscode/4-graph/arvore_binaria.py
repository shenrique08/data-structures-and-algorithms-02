class Node:
    
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None
        
    
    def obterValor(self):
        return self.valor
    
    
    def setEsquerda(self, valorEsquerda):
        self.esquerda = valorEsquerda
        
        
    def setDireita(self, valorDireita):
        self.direita = valorDireita
        
        
    def obterEsquerda(self):
        return self.esquerda
    
    
    def obterDireita(self):
        return self.direita
    
    

node1 = Node(4)
node2 = Node(2)
node3 = Node(5)
node4 = Node(9)
node5 = Node(10)


node1.setEsquerda(node2)
node1.setDireita(node3)
node2.setEsquerda(node4)
node3.setDireita(node5)


print(node1.obterDireita().obterValor())
print(node1.obterEsquerda().obterValor())
#print(node1.obterValorDireita())
