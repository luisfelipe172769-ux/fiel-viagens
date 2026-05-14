-- Criação do Banco de Dados
CREATE DATABASE fiel_viagens_db;
USE fiel_viagens_db;

-- Tabela de Clientes
CREATE TABLE Cliente (
    id_cliente INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    telefone VARCHAR(15),
    email VARCHAR(100) UNIQUE NOT NULL
);

-- Tabela de Destinos
CREATE TABLE Destino (
    id_destino INT AUTO_INCREMENT PRIMARY KEY,
    cidade VARCHAR(50) NOT NULL,
    pais VARCHAR(50) NOT NULL,
    custo_base DECIMAL(10, 2) NOT NULL
);

-- Tabela de Logs do Protocolo (Relacionamento)
CREATE TABLE Log_Protocolo (
    id_log INT AUTO_INCREMENT PRIMARY KEY,
    id_cliente INT,
    id_destino INT,
    status_residencia VARCHAR(50) DEFAULT 'Seguro',
    status_pet VARCHAR(50) DEFAULT 'Alimentado e Bem',
    data_atualizacao DATE,
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente),
    FOREIGN KEY (id_destino) REFERENCES Destino(id_destino)
);

-- Inserindo dados de teste para o relatório
INSERT INTO Cliente (nome, telefone, email) VALUES 
('Mariana Silva', '11999998888', 'mariana@email.com'),
('Roberto Costa', '11977776666', 'roberto@email.com');

INSERT INTO Destino (cidade, pais, custo_base) VALUES 
('Lisboa', 'Portugal', 12400.00),
('Bali', 'Indonésia', 9800.00);

INSERT INTO Log_Protocolo (id_cliente, id_destino, data_atualizacao) VALUES 
(1, 1, '2026-05-14'),
(2, 2, '2026-05-14');