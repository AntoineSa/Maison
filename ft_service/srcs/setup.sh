minikube start --driver=docker;
eval $(minikube docker-env);
docker build -t ngnix:1.0 ./srcs/nginx ;
kubectl apply -f srcs/nginx/deployment.yaml;
kubectl expose deployment/Nginx-node --type="NodePort" --port 80 --port 443;
export POD_NAME=$(kubectl get pods -o go-template --template '{{range .items}}{{.metadata.name}}{{"\n"}}{{end}}');
export NODE_PORT=$(kubectl get services/Nginx-node -o go-template='{{(index .spec.ports 0).nodePort}}')
kubectl apply -f srcs/wordpress/deployment.yaml;
kubectl apply -f srcs/mysql/deployment.yaml;
kubectl apply -f srcs/phpmyadmin/deployment.yaml;
docker build -t ftps:1.0 ./srcs/ftp ;
kubectl apply -f srcs/ftp/deployment.yaml;
kubectl expose deployment/FTPS-node --type="NodePort" --port 21;
kubectl create deployment ingress_controller-node --image= ;
kubectl create deployment graphana-node --image= ;
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml;
kubectl create deployment influxDB-node --image= ;
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml;
