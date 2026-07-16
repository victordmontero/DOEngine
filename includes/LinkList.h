/*
 * ============================================================================
 * DOEngine
 * Copyright (c) 2026 Victor D. Montero, Aneury Perez
 * All Rights Reserved.
 *
 * Licensed under the MIT License.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * 1. The above copyright notice, this license notice, and this disclaimer
 *    MUST be included in all copies or substantial portions of the Software.
 *
 * 2. This notice may not be removed from the original source files distributed
 *    as part of this project.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * ============================================================================
 */


#pragma once

#include <cstddef>
namespace doengine
{
template <class T>
class LinkList
{
  public:
    struct Node
    {
      private:
        Node* _next;

      public:
        T data;

        Node* next() const
        {
            return _next;
        };

        void setNext(Node* node)
        {
            _next = node;
        }

        Node(T d = T(), Node* n = nullptr) : data{d}, _next{n}
        {
        }
    };

    LinkList()
    {
        head = nullptr;
        _len = 0;
    }

    ~LinkList()
    {
        destroy();
    }

    void destroy()
    {
        if (head != nullptr)
        {
            auto next = head->next();
            delete head;
            head = next;

            _len--;
            destroy();
        }
    }

    void insert(T d)
    {
        Node* ne = new Node(d, nullptr);
        if (!head)
            head = ne;
        else
        {
            Node* curr = head;
            while (curr->next() != nullptr)
                curr = curr->next();
            curr->setNext(ne);
        }
        _len++;
    }

    const T remove(T nodeValue)
    {

      Node* prev = findPrev(nodeValue);
      Node* curr = find(nodeValue);
      T deleteValue = T();

      if (curr != nullptr) {
        Node * next = curr->next();
        prev->setNext(next);
        deleteValue = curr->data;
        delete curr;
        curr = nullptr;
        _len--;
      }

      return deleteValue;
    }

    Node* find(T nodeValue)
    {
      return findPrev(nodeValue)->next();
    }

    Node* findPrev(T nodeValue)
    {
        Node* curr = head;
        Node* prev = head;
        while (curr != nullptr){
          if(curr->data == nodeValue)
            break;
          prev = curr;
          curr = curr->next();
        }
        return prev;
    }

    bool insertBefore(Node* node, T nodeValue)
    {
      Node* curr = head;
      Node* prev = head;
      if(curr != nullptr)
      {
        while (curr != nullptr)
        {
          if(curr->data == node->data)
          {
            Node* ne = new Node(nodeValue, curr);
            if(curr->data == prev->data) // If equals, means node is head
            {
              head = ne;
            }
            else
              prev->setNext(ne);
            _len++;
            break;
          }
          prev = curr;
          curr = curr->next();
        }
      }
      else
      {
          insert(nodeValue);
      }
      return true;
    }

    bool insertAfter(Node* node, T nodeValue)
    {
      Node* curr = head;
      if(curr != nullptr)
      {
        while (curr != nullptr)
        {
          if(curr->data == node->data)
          {
            Node* ne = new Node(nodeValue, curr->next());
            curr->setNext(ne);
            _len++;
            break;
          }
          curr = curr->next();
        }
      }
      else
      {
          insert(nodeValue);
      }
      return false;
    } 

    std::size_t getLength() const
    {
        return _len;
    }

    Node* getHead()
    {
        return head;
    }

  private:
    Node* head = {nullptr};
    std::size_t _len;
};

} // namespace doengine
