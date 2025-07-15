# Usa Ubuntu 24.04 como imagen base
FROM ubuntu:24.04

# Evita prompts interactivos
ENV DEBIAN_FRONTEND=noninteractive

# Actualiza e instala herramientas de desarrollo
RUN apt update && apt install -y \
    build-essential \
    g++ \
    cmake \
    pkg-config \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

# Starship (prompt bonito, opcional)
RUN curl -sS https://starship.rs/install.sh | sh -s -- -y
RUN echo 'eval "$(starship init bash)"' >> /root/.bashrc

# Establece el directorio de trabajo
WORKDIR /workspace

# Copia tu código fuente al contenedor
COPY pgm_filters.cpp .

# Compila tu programa
RUN g++ -std=c++17 -Wall -o pgm_filters pgm_filters.cpp

# Permite pasar argumentos (archivo.pgm filtro) al contenedor
ENTRYPOINT ["./pgm_filters"]
