/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 23:14:42 by martiper          #+#    #+#             */
/*   Updated: 2023/06/20 17:52:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine/engine.h>
#include "engine/materials.h"
#include <context/context.h>

typedef t_engine_materials	t_materials;
typedef t_engine_material	t_mat;

void	engine_materials_destroy_material(t_engine_material *mat)
{
	if (!mat)
		return ;
	if (mat->name)
		free(mat->name);
	if (mat->sprites)
		free(mat->sprites);
	free(mat);
}

static t_mat	*__load_mat(char *name)
{
	t_engine_parser_handle	*file;
	t_mat					*mat;
	char					file_path[512];
	char					*line;

	ft_sprintf(file_path, 512, "%s%s%s", MATERIALS_PATH, name, PARSER_EXT);
	file = engine()->parser->begin(file_path);
	if (!file)
		return (NULL);
	mat = ft_calloc(1, sizeof(t_mat));
	if (!mat)
		return (file->end(), NULL);
	mat->name = ft_strdup(name);
	if (!mat->name)
		return (file->end(), engine_materials_destroy_material(mat), NULL);
	line = file->get_prop("count");
	if (!line)
		return (file->end(), engine_materials_destroy_material(mat), NULL);
	mat->count = ft_atoi(line);
	free(line);
	mat->sprites = ft_calloc(mat->count + 1, sizeof(t_engine_sprite *));
	if (!mat->sprites)
		return (file->end(), engine_materials_destroy_material(mat), NULL);
	line = file->get_prop("duration");
	if (!line)
		return (file->end(), engine_materials_destroy_material(mat), NULL);
	mat->animator_duration = ft_atoi(line);
	free(line);
	file->skip_to_list();
	mat->count = 0;
	while (1)
	{
		line = file->get_next();
		if (!line)
			break ;
		mat->sprites[mat->count++] = engine()->assets->get(line);
		free(line);
		if (!mat->sprites[mat->count - 1])
			return (file->end(), engine_materials_destroy_material(mat), NULL);
	}
	file->end();
	return (mat);
}

static t_engine_material	*__get(char *name, bool load)
{
	t_list	*iter;
	t_mat	*mat;

	if (!name)
		return (NULL);
	iter = get_materials()->lst;
	mat = NULL;
	while (iter)
	{
		mat = iter->content;
		if (!ft_strcmp(mat->name, name))
			return (mat);
		iter = iter->next;
	}
	if (load)
	{
		mat = __load_mat(name);
		if (mat)
		{
			iter = ft_lstnew(mat);
			if (!iter)
				return (engine_materials_destroy_material(mat), NULL);
			ft_lstadd_back(&get_materials()->lst, iter);
		}
	}
	return (mat);
}

static void	*materials_create(void)
{
	t_materials	*materials;

	materials = ft_calloc(1, sizeof(t_materials));
	if (!materials)
		return (NULL);
	materials->get = __get;
	return (materials);
}

static void	materials_destroy(void *ptr)
{
	t_materials	*materials;

	materials = ptr;
	ft_lstclear(&materials->lst, \
		(void (*)(void *))engine_materials_destroy_material);
	free(materials);
}

t_materials	*get_materials(void)
{
	return (get_context(\
		CONTEXT_ID_MATERIALS, \
		materials_create, \
		materials_destroy \
	));
}
