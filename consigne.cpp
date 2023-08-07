#
AKIA3MFTUKSUSTJ7F37N
Xw3lsbDxWEzA+kTUx2xjOaD9wkVzQ28Mk2cO6tLI
ami-06db4d78cb1d3bbf9

# Déploiement du serveur web :



# Permet de joindre le compte aws 
provider "aws" {
  region     = "us-east-1"
  access_key = "AKIA3MFTUKSUSTJ7F37N"
  secret_key = "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"
}

# Création de la ressource ( serveur-ec2 -contient l application)
resource "aws_instance" "serveur_dev" {
  ami           = "ami-06db4d78cb1d3bbf9"
  instance_type = "t2.micro"

# nom de  l instance 
  tags = {
    Name = "svr-dev"
  }

  key_name = "key"

# Injection de la configuration EOF (instruction serveur + code )
  user_data = <<-EOF
#!/bin/bash
# Mise à jour du système
apt-get update
apt-get upgrade -y


# Compilation et exécution du code C++
g++ -pg hotel hotel.cpp

./hotel

  EOF

  # Utilisation de l'exécution locale pour la compilation et l'exécution du code C++
  provisioner "local-exec" {
    command = "g++ -o hotel hotel.cpp && ./hotel"
  }
}





--------------------------


# Nom de fichier de configuration 
name: Déploiement # Nom du workflow
on:
  push:
    branches:
      - main # Déclenche le déploiement lorsque des modifications sont poussées vers la branche "main"

jobs:
  deploy:
    runs-on: ubuntu-latest                            # Spécifie que le déploiement s exécute sur une machine Ubuntu

    steps:
    - name: Récupération du code source
      uses: actions/checkout@v2 # Récupère le code du dépôt GitHub

    - name: Installation de  Terraform
      uses: hashicorp/setup-terraform@v1
      with:
        terraform_version: 1.4.6   # Installe la version 1.4.6 de Terraform

    

    - name: Terraform Initialisation
      run: terraform init            # Initialise Terraform dans le répertoire du projet


    
    - name: Terraform Application 
      run: terraform apply -auto-approve # Applique les modifications Terraform automatiquement





-------------------------------

nano /etc/apt/sources.list 
deb http://ppa.launchpad.net/ansible/ansible/ubuntu focal main
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 93C4A3FD7BB9C367
sudo apt update
sudo apt install ansible

-(backup - localhost)

nano /etc/ansible/hosts
[serveurpilote]
192.168.100.10

[productionec2]
54.160.180.191

[backup]
192.168.100.11
# Test des accès vers les clients
ansible all -m ping (accès ok )

# Commande generale
ansible-playbook
man ansible-playbook
--syntax-check 
--list-hosts
--step
-v   : simple affichage
-vvv : entrer/sortie 

# Execution d un playbook 
ansible-playbook déploiement.yaml -vvv


- name: Save state
run: echo "{name}={value}" >> $GITHUB_STATE

- name: Set output
run: echo "{name}={value}" >> $GITHUB_OUTPUT
* 2 * * * /root/devops/

------------------------
---
- name: deploimeent
  hosts: 
  gather_facts: false
  tasks:
    - name: 
      command: git status --porcelain /root/devops/
      register: git_status

    - name: 
      command: |
        cd /root/devops/
        git add main.tf
        git commit -m "new"
        git push
      when: git_status.stdout != ""

------------
#!/bin/bash

# Chemin local du répertoire à sauvegarder
source_dir="/root/devops"

# Chemin sur le serveur distant où sauvegarder les fichiers
destination_dir="/root/"

# Création de la sauvegarde locale dans un dossier temporaire
timestamp=$(date +%Y%m%d%H%M%S)
backup_dir="/tmp/backup_$timestamp"
mkdir "$backup_dir"
cp -r "$source_dir" "$backup_dir/"

# Envoi de la sauvegarde sur le serveur distant en utilisant scp
scp -r "$backup_dir" "$destination_dir"

# Suppression du dossier temporaire de la sauvegarde locale
rm -rf "$backup_dir"

echo "Sauvegarde effectuée avec succès sur le serveur distant."

0 0 * * * /chemin/vers/le/script.sh

--------------












# Installation des dépendances pour WordPress et MariaDB
apt-get install -y curl unzip apache2 mariadb-server mariadb-client php libapache2-mod-php php-cli php-mysql php-zip php-curl php-xml wget

# Configuration de la base de données MariaDB
mysql -e "CREATE DATABASE wordpress;"
mysql -e "CREATE USER 'wordpress'@'localhost' IDENTIFIED BY 'password';"
mysql -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'wordpress'@'localhost';"
mysql -e "FLUSH PRIVILEGES;"

# Téléchargement et configuration de WordPress
cd /var/www/html
wget -c http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
mv wordpress/* .
rm -rf wordpress latest.tar.gz
chown -R www-data:www-data /var/www/html

# Configuration de wp-config.php
mv wp-config-sample.php wp-config.php
sed -i "s/database_name_here/wordpress/" wp-config.php
sed -i "s/username_here/wordpress/" wp-config.php
sed -i "s/password_here/password/" wp-config.php




