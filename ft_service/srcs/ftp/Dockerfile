# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/28 12:31:40 by asablayr          #+#    #+#              #
#    Updated: 2020/05/28 12:52:09 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	alpine

RUN	apk update && apk add nss-tools vsftpd && \
	wget -q -O mkcert https://github.com/FiloSottile/mkcert/releases/download/v1.4.1/mkcert-v1.4.1-linux-amd64 && \
	chmod +x mkcert && mv mkcert /usr/local/bin/ && \
	mkcert -install

COPY	srcs/ftp/vsftpd.conf etc/vsftpd/

ENTRYPOINT	mkcert localhost && \
		mv localhost.pem /etc/ssl/certs/ && \
		mv localhost-key.pem /etc/ssl/private/ && \
		bin/sh
