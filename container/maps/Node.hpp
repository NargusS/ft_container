/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:14:37 by achane-l          #+#    #+#             */
/*   Updated: 2023/01/26 17:45:28 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct Node{
	bool color;
	// value_type	value;
	Node	*parent;
	Node	*left;
	Node	*right;
};

typedef Node* Nodeptr;